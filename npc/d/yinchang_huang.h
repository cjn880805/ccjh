//yinchang_huang.h

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_huang);

virtual void create()
{
    set_name("黄老怪", "huang yaoshi");
    set("title", "桃花岛主");
    set("nickname",  "东邪"  );
    set("gender", "男性");
    set("age", 42);
    set("icon",old_man2);

    set("long", "他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);
	
    set("hp", 3000);
    set("max_hp", 9000);
    set("mp", 3500);
    set("max_mp", 3500);
    set("mp_factor", 100);
	
    set("combat_exp", 1500000);
    
	
    set_skill("force", 150);             // 基本内功
    set_skill("bibo_shengong", 150);     // 碧波神功
    set_skill("claw", 150);              // 基本爪法
    set_skill("hand", 150);              // 基本手法
    set_skill("finger", 170);            // 基本指法
    set_skill("tanzhi_shentong", 170);   // 弹指神通
    set_skill("unarmed", 180);           // 基本拳脚
    set_skill("strike", 180);            // 基本拳脚
    set_skill("luoying_shenzhang", 180);     // 落英神剑掌
    set_skill("xuanfeng_leg", 180);      // 旋风扫叶腿
    set_skill("dodge", 150);             // 基本躲闪
    set_skill("anying_fuxiang", 120);    // 暗影浮香
    set_skill("parry", 150);             // 基本招架
    set_skill("sword", 200);             // 基本剑法
    set_skill("luoying_shenjian", 200);  // 落英神剑
    set_skill("yuxiao_jianfa", 200);       // 玉箫剑法
    set_skill("lanhua_shou", 200);       // 兰花拂穴手
    set_skill("qimen_wuxing",150);       // 奇门五行
    set_skill("count",150);              // 阴阳八卦
    set_skill("literate",150);           // 读书识字
	
    map_skill("force"  , "bibo_shengong");
    map_skill("finger" , "tanzhi_shentong");
    map_skill("hand"   , "lanhua_shou");
    map_skill("unarmed", "luoying_shenzhang");
    map_skill("strike" , "xuanfeng_leg");
    map_skill("dodge"  , "anying_fuxiang");
    map_skill("parry"  , "luoying_shenjian");
    map_skill("sword"  , "yuxiao_jianfa");
	
    create_family("桃花岛", 1, "岛主");
	
    carry_object("cloth")->wear();
    carry_object("yuxiao")->wield();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say("  七灯大师，您贵位一国天子却出家为僧，此句深藏身与名，您必深得其意。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="yideng-dashi")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;