// youcao.c 幽草
//sound 2001-07-16

NPC_BEGIN(CNmurong_youcao);

virtual void create()
{
	set_name("幽花", "you cao");
	set("gender", "女性");
	set("age", 20);      
	set("title","丫鬟");
	set("str", 25);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("per", 30);
	set("icon",young_woman12);
	
	set("combat_exp", 13000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_hp",1000);
	set("hp",1000);
	set("mp",1000);
	set("max_mp",1000);
	set("mp_factor",30);
	set("score", 8000);
	
	set_skill("cuff", 50);
	set_skill("parry",40);
	set_skill("yanling_shenfa",70);
	set_skill("dodge", 70);
	set_skill("force",70);
	set_skill("shenyuan_gong",70);
	
	map_skill("force","shenyuan_gong");
	map_skill("dodge","yanling_shenfa");
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	
	carry_object("shoe")->wear();
//	carry_object("red_silk")->wear();
//	carry_object("skirt1")->wear();
	
	set_inquiry("名字", "我就是曼佗罗山庄的丫鬟幽花。");
	set_inquiry("这里", "这里是曼佗罗山庄，难道你没有听说过？");
	set_inquiry("传闻",  "花肥房的厉妈妈经常用人做花肥，千万别让他看见你。");
	set_inquiry("阿红",  "阿红住在听香水榭，是慕容公子的贴身丫鬟，跟阿绿两个人一同侍奉公子。");
	set_inquiry("阿绿",  "阿绿姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。");
	set_inquiry("王语甜", "王姑娘是我家小姐。");
	set_inquiry("听香水榭", "听香水榭是阿红姑娘住的地方，离这里不远。");
	set_inquiry("琴韵小筑", "琴韵小筑是阿绿姑娘住的地方，坐小舟有三九水路就到了。");
	set_inquiry("曼佗罗山庄",  "这里就是曼佗罗山庄了。");
	
	set("chat_chance",20);       
}

virtual char *chat_msg()
{
	return "幽草自言自语到：“千万别让严妈妈看见你，要不会把你作成花肥的。”";
}

NPC_END;