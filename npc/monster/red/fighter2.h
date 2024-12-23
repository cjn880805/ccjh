//Lanwood 2000-09-17

FIGHTER_BEGIN(CNwiz_fighter2);

void create()
{
	set_name("战神", "zhan shen");

	set("title", "青年组登记员");
	set("icon", boy2);
	
	set("chname", "战神");
	set("channel", "f2");

	set("wait_time", 10);

	set("grant", 80);
				
	set("judge/attr", "level");
	set("judge/min", 30);
	set("judge/max", 60);
	set("judge/desc", "等级在30级到60级之间（不含60级）。");

	set("biwu/name", "青年比武大会");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

//-------------------------------------------
		set("icon",young_man2);
	
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 10);
	set("chat_chance_combat", 15);

	set("max_hp",9000);
	set("mp", 6500);
	set("max_mp", 6500);
	set("mp_factor", 150);
	
	
	set("combat_exp", 5000000);
    
	set_skill("force", 280);             // 基本内功
	set_skill("claw", 200);              // 基本爪法
	set_skill("hand", 220);              // 基本手法
	set_skill("finger", 240);            // 基本指法
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("strike", 220);            // 基本拳脚
	set_skill("leg", 220);	           // 基本拳脚
    set_skill("dodge", 280);             // 基本躲闪
    set_skill("parry", 280);             // 基本招架
    set_skill("sword", 300);             // 基本剑法

    set_skill("anying_fuxiang", 280);    // 暗影浮香
    set_skill("tanzhi_shentong", 300);   // 弹指神通
    set_skill("xuanfeng_leg", 280);      // 旋风扫叶腿
    set_skill("luoying_shenzhang", 280);     // 落英神剑掌
	set_skill("bibo_shengong", 300);     // 碧波神功
    set_skill("luoying_shenjian", 280);  // 落英神剑
    set_skill("yuxiao_jianfa", 300);       // 玉箫剑法
    set_skill("lanhua_shou", 280);       // 兰花拂穴手
    set_skill("qimen_wuxing",300);       // 奇门五行
    set_skill("literate", 300);           // 读书识字
	
    map_skill("force"  , "bibo_shengong");
    map_skill("finger" , "tanzhi_shentong");
    map_skill("hand"   , "lanhua_shou");
	map_skill("unarmed", "luoying_shenzhang");
    map_skill("strike", "luoying_shenzhang");
	map_skill("leg", "xuanfeng_leg");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("parry"  , "tanzhi_shentong");
    map_skill("sword"  , "tanzhi_shentong");
	
	prepare_skill("finger", "tanzhi_shentong");
	prepare_skill("hand", "lanhua_shou");

	carry_object("bluecloth")->wear();
	carry_object("yuxiao");
//---------------------------------------------------
	Load();
};

char * chat_msg_combat()
{
	switch(random(4))
	{
	case 0:
		perform_action("force powerup", 1);
		break;
	case 1:
		perform_action("hand fuxue", 1);
		break;
	case 2:
		perform_action("finger hui", 1);
		break;
	case 3:
		perform_action("force recover", 0);
		break;
	}

	return 0;
}

FIGHTER_END;




