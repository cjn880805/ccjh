#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../server/Channel.h"

#include "../npc/18dy/dy_master.h"
#include "../npc/18dy/boss.h"
#include "../npc/18dy/boss/ningfeng.h"
#include "../npc/18dy/boss/dajianshi_lante.h"
#include "../npc/18dy/boss/yijian_feixian.h"
#include "../npc/18dy/boss/wanbaolou_sisi.h"
#include "../npc/18dy/boss/biluo_leng.h"
#include "../npc/18dy/boss/jinshiyi.h"
#include "../npc/18dy/boss/yong_rong.h"
#include "../npc/18dy/boss/tiancai_hunhun.h"
#include "../npc/18dy/boss/yifei.h"
#include "../npc/18dy/boss/shuizhizi.h"
#include "../npc/18dy/boss/benxiong.h"
#include "../npc/18dy/boss/chongtian.h"
#include "../npc/18dy/boss/xinxinshou.h"
#include "../npc/18dy/boss/bingliang_bohe.h"
#include "../npc/18dy/boss/tudou.h"
#include "../npc/18dy/boss/ningcc.h"
#include "../npc/18dy/boss/fengyucansheng.h"
#include "../npc/18dy/boss/shuilinyan.h"
#include "../npc/18dy/boss/zhangdanfeng.h"
#include "../npc/18dy/boss/ziying.h"
#include "../npc/18dy/boss/wangcai.h"
#include "../npc/18dy/boss/linglan.h"

#include "../npc/18dy/monster.h"
#include "../npc/18dy/dy_daiyanren.h"

#include "../npc/18dy/diyu_shizhe1.h"
#include "../npc/18dy/diyu_shizhe2.h"
#include "../npc/18dy/diyu_shizhe3.h"
#include "../npc/18dy/diyu_shizhe4.h"
#include "../npc/18dy/diyu_shizhe5.h"
#include "../npc/18dy/diyu_shizhe6.h"
#include "../npc/18dy/diyu_shizhe7.h"
#include "../npc/18dy/diyu_shizhe8.h"
#include "../npc/18dy/diyu_shizhe9.h"
#include "../npc/18dy/diyu_shizhe10.h"
#include "../npc/18dy/diyu_shizhe11.h"
#include "../npc/18dy/diyu_shizhe12.h"
#include "../npc/18dy/diyu_shizhe13.h"
#include "../npc/18dy/diyu_shizhe14.h"
#include "../npc/18dy/diyu_shizhe15.h"
#include "../npc/18dy/diyu_shizhe16.h"
#include "../npc/18dy/diyu_shizhe17.h"
#include "../npc/18dy/diyu_shizhe18.h"
#include "../npc/18dy/diyu_shizhe19.h"
#include "../npc/18dy/diyu_shizhe20.h"
#include "../npc/18dy/diyu_shizhe21.h"
#include "../npc/18dy/diyu_shizhe22.h"

#include "../npc/18dy/dy_monster/dy1_monster.h"
#include "../npc/18dy/dy_monster/dy2_monster.h"
#include "../npc/18dy/dy_monster/dy3_monster.h"
#include "../npc/18dy/dy_monster/dy4_monster.h"
#include "../npc/18dy/dy_monster/dy5_monster.h"
#include "../npc/18dy/dy_monster/dy6_monster.h"
#include "../npc/18dy/dy_monster/dy7_monster.h"
#include "../npc/18dy/dy_monster/dy8_monster.h"
#include "../npc/18dy/dy_monster/dy9_monster.h"
#include "../npc/18dy/dy_monster/dy10_monster.h"
#include "../npc/18dy/dy_monster/dy11_monster.h"
#include "../npc/18dy/dy_monster/dy12_monster.h"
#include "../npc/18dy/dy_monster/dy13_monster.h"
#include "../npc/18dy/dy_monster/dy14_monster.h"
#include "../npc/18dy/dy_monster/dy15_monster.h"
#include "../npc/18dy/dy_monster/dy16_monster.h"
#include "../npc/18dy/dy_monster/dy17_monster.h"
#include "../npc/18dy/dy_monster/dy18_monster.h"
#include "../npc/18dy/dy_monster/dy19_monster.h"
#include "../npc/18dy/dy_monster/dy20_monster.h"
#include "../npc/18dy/dy_monster/dy21_monster.h"
#include "../npc/18dy/dy_monster/dy22_monster.h"


CNpc * LoadNPC_18dy(string npc_name)
{
	CNpc * t = 0;
	
	if(npc_name == "dy_master")
		t = new CNdy_master();
	
	else if(npc_name == "ningfeng")
		t = new CNningfeng();
	else if(npc_name == "dajianshi_lante")
		t = new CNdajianshi_lante();
	else if(npc_name == "wanbaolou_sisi")
		t = new CNwanbaolou_sisi();
	else if(npc_name == "yijian_feixian")
		t = new CNyijian_feixian();
	else if(npc_name == "biluo_leng")
		t = new CNbiluo_leng();
	else if(npc_name == "jinshiyi")
		t = new CNjinshiyi();
	else if(npc_name == "tiancai_hunhun")
		t = new CNtiancai_hunhun();
	else if(npc_name == "yong_rong")
		t = new CNyong_rong();
	else if(npc_name == "yifei")
		t = new CNyifei();
	else if(npc_name == "shuizhizi")
		t = new CNshuizhizi();
	else if(npc_name == "benxiong")
		t = new CNbenxiong();
	else if(npc_name == "chongtian")
		t = new CNchongtian();
	else if(npc_name == "xinxinshou")
		t = new CNxinxinshou();
	else if(npc_name == "bingliang_bohe")
		t = new CNbingliang_bohe();
	else if(npc_name == "tudou")
		t = new CNtudou();
	else if(npc_name == "ningcc")
		t = new CNningcc();
	else if(npc_name == "fengyucansheng")
		t = new CNfengyucansheng();
	else if(npc_name == "shuilinyan")
		t = new CNshuilinyan();
	else if(npc_name == "zhangdanfeng")
		t = new CNzhangdanfeng();
	else if(npc_name == "ziying")
		t = new CNziying();
	else if(npc_name == "wangcai")
		t = new CNwangcai();
	else if(npc_name == "linglan")
		t = new CNlinglan();
	
	else if(npc_name == "dy_daiyanren")
		t = new CNdy_daiyanren();
	
	else if(npc_name == "diyu_shizhe1")
		t = new CNdiyu_shizhe1();
	else if(npc_name == "diyu_shizhe2")
		t = new CNdiyu_shizhe2();
	else if(npc_name == "diyu_shizhe3")
		t = new CNdiyu_shizhe3();
	else if(npc_name == "diyu_shizhe4")
		t = new CNdiyu_shizhe4();
	else if(npc_name == "diyu_shizhe5")
		t = new CNdiyu_shizhe5();
	else if(npc_name == "diyu_shizhe6")
		t = new CNdiyu_shizhe6();
	else if(npc_name == "diyu_shizhe7")
		t = new CNdiyu_shizhe7();
	else if(npc_name == "diyu_shizhe8")
		t = new CNdiyu_shizhe8();
	else if(npc_name == "diyu_shizhe9")
		t = new CNdiyu_shizhe9();
	else if(npc_name == "diyu_shizhe10")
		t = new CNdiyu_shizhe10();
	else if(npc_name == "diyu_shizhe11")
		t = new CNdiyu_shizhe11();
	else if(npc_name == "diyu_shizhe12")
		t = new CNdiyu_shizhe12();
	else if(npc_name == "diyu_shizhe13")
		t = new CNdiyu_shizhe13();
	else if(npc_name == "diyu_shizhe14")
		t = new CNdiyu_shizhe14();
	else if(npc_name == "diyu_shizhe15")
		t = new CNdiyu_shizhe15();
	else if(npc_name == "diyu_shizhe16")
		t = new CNdiyu_shizhe16();
	else if(npc_name == "diyu_shizhe17")
		t = new CNdiyu_shizhe17();
	else if(npc_name == "diyu_shizhe18")
		t = new CNdiyu_shizhe18();
	else if(npc_name == "diyu_shizhe19")
		t = new CNdiyu_shizhe19();
	else if(npc_name == "diyu_shizhe20")
		t = new CNdiyu_shizhe20();
	else if(npc_name == "diyu_shizhe21")
		t = new CNdiyu_shizhe21();
	else if(npc_name == "diyu_shizhe22")
		t = new CNdiyu_shizhe22();
	
	else if(npc_name == "dy1_monster")
		t = new CNdy1_monster();
	else if(npc_name == "dy2_monster")
		t = new CNdy2_monster();
	else if(npc_name == "dy3_monster")
		t = new CNdy3_monster();
	else if(npc_name == "dy4_monster")
		t = new CNdy4_monster();
	else if(npc_name == "dy5_monster")
		t = new CNdy5_monster();
	else if(npc_name == "dy6_monster")
		t = new CNdy6_monster();
	else if(npc_name == "dy7_monster")
		t = new CNdy7_monster();
	else if(npc_name == "dy8_monster")
		t = new CNdy8_monster();
	else if(npc_name == "dy9_monster")
		t = new CNdy9_monster();
	else if(npc_name == "dy10_monster")
		t = new CNdy10_monster();
	else if(npc_name == "dy11_monster")
		t = new CNdy11_monster();
	else if(npc_name == "dy12_monster")
		t = new CNdy12_monster();
	else if(npc_name == "dy13_monster")
		t = new CNdy13_monster();
	else if(npc_name == "dy14_monster")
		t = new CNdy14_monster();
	else if(npc_name == "dy15_monster")
		t = new CNdy15_monster();
	else if(npc_name == "dy16_monster")
		t = new CNdy16_monster();
	else if(npc_name == "dy17_monster")
		t = new CNdy17_monster();
	else if(npc_name == "dy18_monster")
		t = new CNdy18_monster();
	else if(npc_name == "dy19_monster")
		t = new CNdy19_monster();
	else if(npc_name == "dy20_monster")
		t = new CNdy20_monster();
	else if(npc_name == "dy21_monster")
		t = new CNdy21_monster();
	else if(npc_name == "dy22_monster")
		t = new CNdy22_monster();

	return t;
}