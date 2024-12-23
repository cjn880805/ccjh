// gongsun.c 公孙乾
//sound 2001-07-16

NPC_BEGIN(CNmurong_gongsun);

virtual void create()
{
	set_name("公冶坤", "gongye gan");
	set("title","赤霞庄庄主");
	set("long", "他就是姑苏慕容赤霞庄的庄主。");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 46);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",young_man2);
	
	set("max_hp", 2500);
	set("hp", 1000);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("combat_exp", 850000);
	set("score", 85000);

	set("chat_chance_combat", 50);
	
	set_skill("dodge",130);
	set_skill("force", 130);
	set_skill("shenyuan_gong", 130);
	set_skill("yanling_shenfa", 130);
	set_skill("parry", 130);
	set_skill("murong_jianfa", 130);
	set_skill("literate", 130);
	set_skill("sword", 130);
	set_skill("finger", 130);
	set_skill("canhe_zhi", 130);
	set_skill("strike", 130);
	set_skill("xingyi_zhang", 130);
	
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("strike", "xingyi_zhang");
	map_skill("finger", "canhe_zhi");
	map_skill("parry", "murong_jianfa");
	map_skill("sword", "murong_jianfa");	
	prepare_skill("finger", "canhe_zhi");
	prepare_skill("strike", "xingyi_zhang");
	
	
	carry_object("cloth2")->wear();
	carry_object("changjian")->wield();        
	create_family("姑苏慕容",3,"弟子");
	
	set_inquiry("名字", "我就是姑苏慕容赤霞庄庄主公孙坤。");
	set_inquiry("这里", "这里是大名鼎鼎的燕子坞，难道你没有听说过？");
	set_inquiry("传闻", "慕容公子的以彼之道，还施彼身天下闻名。");
	set_inquiry("阿红", "阿红住在听香水榭，是慕容公子的贴身丫鬟，跟阿绿两个人一同侍奉公子。");
	set_inquiry("阿绿", "阿绿姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。");
	set_inquiry("王语甜", "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。");
	set_inquiry("邓千川", "邓千川是我大哥，是燕子坞青云庄的庄主。");
	set_inquiry("包相同", "包相同是我三弟，是燕子坞金凤庄的庄主，他总是喜欢说“非也，非也”。");
	set_inquiry("风波善", "风波善是我四弟，是燕子坞玄霜庄的庄主，他就是喜欢跟别人打架。");
	set_inquiry("听香水榭",  "听香水榭是阿红姑娘住的地方，离这里不远。");
	set_inquiry("琴韵小筑",  "琴韵小筑是阿绿姑娘住的地方，坐小舟有三九水路就到了。");
	set_inquiry("曼佗罗山庄", "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。");
	set_inquiry("还施水阁", "这是燕子坞的秘密之所在，我可不便对你说。");
	
}

virtual char * chat_msg_combat()
{
	perform_action("sword qixing", 1);

	return 0;
}
/*
void attempt_apprentice(object ob)
{
	command("say 嗯，看你还是个学武的料，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("title","姑苏慕容第四代弟子");
}
*/
NPC_END;