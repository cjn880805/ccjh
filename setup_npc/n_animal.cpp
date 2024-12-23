#include "stdafx.h"
#include "../server/Room.h"
#include "../std/Money.h"
#include "../std/Vendor.h"
#include "../std/BankOwner.h"
#include "../std/Corpse.h"
#include "../server/User.h"
#include "../server/Channel.h"


//-----------------------------------------------------------------
//
//	动物NPC
//	author:		Zou Wen Bin
//	date:		2000-12-26
//
//-----------------------------------------------------------------

#include "../npc/animal/animal_baima.h"
#include "../npc/animal/animal_baitu.h"
#include "../npc/animal/animal_banjiu.h"
#include "../npc/animal/animal_bat.h"
#include "../npc/animal/animal_bear.h"
#include "../npc/animal/animal_boe.h"
#include "../npc/animal/animal_buck.h"
#include "../npc/animal/animal_caihuashe.h"
#include "../npc/animal/animal_camel.h"
#include "../npc/animal/animal_cow.h"
#include "../npc/animal/animal_dandinghe.h"
#include "../npc/animal/animal_deer.h"
#include "../npc/animal/animal_dog.h"
#include "../npc/animal/animal_dongbeihu.h"
#include "../npc/animal/animal_duck.h"
#include "../npc/animal/animal_dushe.h"
#include "../npc/animal/animal_duzhizhu.h"
#include "../npc/animal/animal_eagle.h"
#include "../npc/animal/animal_fox.h"
#include "../npc/animal/animal_frog.h"
#include "../npc/animal/animal_fushe.h"
#include "../npc/animal/animal_heima.h"
#include "../npc/animal/animal_hongma.h"
#include "../npc/animal/animal_huangbiaoma.h"
#include "../npc/animal/animal_hudie.h"
#include "../npc/animal/animal_jinshe.h"
#include "../npc/animal/animal_lamb.h"
#include "../npc/animal/animal_laofu.h"
#include "../npc/animal/animal_lion.h"
#include "../npc/animal/animal_littlebee.h"
#include "../npc/animal/animal_littlemonkey.h"
#include "../npc/animal/animal_liuma.h"
#include "../npc/animal/animal_mangshe.h"
#include "../npc/animal/animal_maoniu.h"
#include "../npc/animal/animal_monkey.h"
#include "../npc/animal/animal_qingshe.h"
#include "../npc/animal/animal_shachong.h"
#include "../npc/animal/animal_shanyang.h"
#include "../npc/animal/animal_sheep.h"
#include "../npc/animal/animal_snake.h"
#include "../npc/animal/animal_songshu.h"
#include "../npc/animal/animal_wolf2.h"
#include "../npc/animal/animal_wolfdog.h"
#include "../npc/animal/animal_wubushe.h"
#include "../npc/animal/animal_wugui.h"
#include "../npc/animal/animal_wuya.h"
#include "../npc/animal/animal_xiezi.h"
#include "../npc/animal/animal_yetu.h"
#include "../npc/animal/animal_yezhu.h"
#include "../npc/animal/animal_yucongma.h"
#include "../npc/animal/animal_yufeng.h"
#include "../npc/animal/animal_zaohongma.h"
#include "../npc/animal/animal_ziliuma.h"
#include "../npc/animal/animal_huananhu.h"
#include "../npc/animal/animal_bigmonkey.h"
#include "../npc/animal/animal_wangcai.h"

//逍遥任务中的道具
#include "../item/goods/d/xy/baiyang.h"
#include "../item/goods/d/xy/wuji.h"

CNpc * LoadNPC_animal(string npc_name)
{
	CNpc * t = 0;

	//动物
	if(npc_name == "animal_ziliuma")
		t = new CNAnimal_ziliuma();
	else if(npc_name == "animal_zaohongma")
		t = new CNAnimal_zaohongma();
	else if(npc_name == "animal_yufeng")
		t = new CNAnimal_yufeng();
	else if(npc_name == "animal_yucongma")
		t = new CNAnimal_yucongma();
	else if(npc_name == "animal_yezhu")
		t = new CNAnimal_yezhu();
	else if(npc_name == "animal_yetu")
		t = new CNAnimal_yetu();
	else if(npc_name == "animal_xiezi")
		t = new CNAnimal_xiezi();
	else if(npc_name == "animal_wuya")
		t = new CNAnimal_wuya();
	else if(npc_name == "animal_maoniu")
		t = new CNAnimal_maoniu();
	else if(npc_name == "animal_wubushe")
		t = new CNAnimal_wubushe();
	else if(npc_name == "animal_wolfdog")
		t = new CNAnimal_wolfdog();
	else if(npc_name == "animal_wolf2")
		t = new CNAnimal_wolf2();
	else if(npc_name == "animal_songshu")
		t = new CNAnimal_songshu();
	else if(npc_name == "animal_snake")
		t = new CNAnimal_snake();
	else if(npc_name == "animal_sheep")
		t = new CNAnimal_sheep();
	else if(npc_name == "animal_shanyang")
		t = new CNAnimal_shanyang();
	else if(npc_name == "animal_shachong")
		t = new CNAnimal_shachong();
	else if(npc_name == "animal_qingshe")
		t = new CNAnimal_qingshe();
	else if(npc_name == "animal_monkey")
		t = new CNAnimal_monkey();
	else if(npc_name == "animal_wugui")
		t = new CNAnimal_wugui();
	else if(npc_name == "animal_mangshe")
		t = new CNAnimal_mangshe();
	else if(npc_name == "animal_liuma")
		t = new CNAnimal_liuma();
	else if(npc_name == "animal_littlemonkey")
		t = new CNAnimal_littlemonkey();
	else if(npc_name == "animal_littlebee")
		t = new CNAnimal_littlebee();
	else if(npc_name == "animal_lion")
		t = new CNAnimal_lion();
	else if(npc_name == "animal_laofu")
		t = new CNAnimal_laofu();
	else if(npc_name == "animal_lamb")
		t = new CNAnimal_lamb();
	else if(npc_name == "animal_jinshe")
		t = new CNAnimal_jinshe();
	else if(npc_name == "animal_hudie")
		t = new CNAnimal_hudie();
	else if(npc_name == "animal_huangbiaoma")
		t = new CNAnimal_huangbiaoma();
	else if(npc_name == "animal_huananhu")
		t = new CNAnimal_huananhu();
	else if(npc_name == "animal_hongma")
		t = new CNAnimal_hongma();
	else if(npc_name == "animal_heima")
		t = new CNAnimal_heima();
	else if(npc_name == "animal_fushe")
		t = new CNAnimal_fushe();

	else if(npc_name == "animal_frog")
		t = new CNAnimal_frog();
	else if(npc_name == "animal_fox")
		t = new CNAnimal_fox();
	else if(npc_name == "animal_eagle")
		t = new CNAnimal_eagle();
	else if(npc_name == "animal_duzhizhu")
		t = new CNAnimal_duzhizhu();
	else if(npc_name == "animal_dushe")
		t = new CNAnimal_dushe();
	else if(npc_name == "animal_duck")
		t = new CNAnimal_duck();
	else if(npc_name == "animal_dongbeihu")
		t = new CNAnimal_dongbeihu();
	else if(npc_name == "animal_dog")
		t = new CNAnimal_dog();
	else if(npc_name == "animal_deer")
		t = new CNAnimal_deer();
	else if(npc_name == "animal_dandinghe")
		t = new CNAnimal_dandinghe();
	else if(npc_name == "animal_cow")
		t = new CNAnimal_cow();
	else if(npc_name == "animal_camel")
		t = new CNAnimal_camel();
	else if(npc_name == "animal_baima")
		t = new CNAnimal_baima();
	else if(npc_name == "animal_buck")
		t = new CNAnimal_buck();
	else if(npc_name == "animal_doe")
		t = new CNAnimal_doe();
	else if(npc_name == "animal_bigmonkey")
		t = new CNAnimal_bigmonkey();
	else if(npc_name == "animal_bear")
		t = new CNAnimal_bear();
	else if(npc_name == "animal_bat")
		t = new CNAnimal_bat();
	else if(npc_name == "animal_banjiu")
		t = new CNAnimal_banjiu();
	else if(npc_name == "animal_baitu")
		t = new CNAnimal_baitu();
	else if(npc_name == "animal_caihuashe")
		t = new CNAnimal_caihuashe();
	else if(npc_name == "animal_wangcai")
		t = new CNAnimal_wangcai();

	else if(npc_name == "baiyang")
		t = new CNbaiyang();
	else if(npc_name == "wuji")
		t = new CNwuji();

	return t;
}