//xiaojindai.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_xiaojindai);

virtual void create()
{
	set_name("萧近岱","xiao jin dai");

	set("gender", "男性");
	set("nickname","黑衣僧");
	set("age", 28);
	set("long","他就是丐帮前任帮主萧大哥的父亲，潜伏少林数十年了。他身穿一件普通的黑僧袍，腰间用一条麻绳随便一系。他身高六尺有余，体格十分魁梧，长有一张线条粗旷、十分男性化的脸庞，双目如电，炯炯有神。");
	set("attitude", "peaceful");
 	set("icon",young_man4);
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // 基本内功
	set_skill("hunyuan_yiqi", 120);      // 混天气功
	set_skill("unarmed", 120);           // 基本拳脚
	set_skill("jingang_quan", 120);      // 降龙十八掌
	set_skill("dodge", 120);      	     // 基本躲闪
	set_skill("shaolin_shenfa", 120);    // 逍遥游
	set_skill("parry", 120);             // 基本招架
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("unarmed", "jingang_quan");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "jingang_quan");

	carry_object("cloth")->wear();
};


NPC_END;
