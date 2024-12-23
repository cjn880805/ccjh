// deng.c 邓百川
//sound 2001-07-16

NPC_BEGIN(CNmurong_deng);

virtual void create()
{
	set_name("邓千川", "deng baichuan");
	set("title","青云庄庄主");
	set("long", "他就是姑苏慕容青云庄的庄主。");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 36);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("icon",young_man6);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 100);
	set("combat_exp", 750000);
	set("score", 85000);
	
	set_skill("finger",130);
	set_skill("dodge",130);
	set_skill("force", 130);
	set_skill("shenyuan_gong", 130);
	set_skill("yanling_shenfa", 130);
	set_skill("parry", 130);
	set_skill("canhe_zhi", 150);
	set_skill("literate", 130);
	
	map_skill("force", "shenyuan_gong");
	map_skill("dodge", "yanling_shenfa");
	map_skill("parry", "xingyi_zhang");
	map_skill("finger", "canhe_zhi");	
	
	prepare_skill("finger","canhe_zhi");
	
	carry_object("cloth")->wear();        
	create_family("姑苏慕容",3,"弟子");
	
	set_inquiry("名字", "我就是姑苏慕容青云庄庄主邓千川。");
	set_inquiry("这里", "这里是大名鼎鼎的燕子坞，难道你没有听说过？");
	set_inquiry("传闻",  "慕容公子的以彼之道，还施彼身天下闻名。");
	set_inquiry("阿红",  "阿红住在听香水榭，是慕容公子的贴身丫鬟，跟阿绿两个人一同侍奉公子。");
	set_inquiry("阿绿",  "阿绿姑娘住在琴韵小筑，所有要拜见慕容公子的人都要由她那里经过。");
	set_inquiry("王语甜", "王姑娘是慕容公子的表妹，不知道什么时候他们成亲。");
	set_inquiry("公孙坤", "公孙乾是我二弟，是燕子坞赤霞庄的庄主。");
	set_inquiry("包相同", "包相同是我三弟，是燕子坞金凤庄的庄主，他总是喜欢说“非也，非也”。");
	set_inquiry("风波善", "风波善是我四弟，是燕子坞玄霜庄的庄主，他就是喜欢跟别人打架。");
	set_inquiry("听香水榭",  "听香水榭是阿红姑娘住的地方，离这里不远。");
	set_inquiry("琴韵小筑",  "琴韵小筑是阿绿姑娘住的地方，坐小舟有三九水路就到了。");
	set_inquiry("曼佗罗山庄", "曼佗罗山庄是公子的姑妈住的地方，平时连我都不敢去。");
	set_inquiry("还施水阁", "这是燕子坞的秘密之所在，我可不便对你说。");
	
	set("chat_chance",20);
}

virtual char * chat_msg()		//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return 	"邓千川自言自语到：“上回多亏了公子的归元丹，要么四弟的命差点就丢了。”";
	case 1:
		return 	"邓千川道：“老爷生前最钟爱的那本书也一同下葬了。";
	case 2:
		return 	"邓千川道：“老爷去的那天我的头都快磕破了。";
	}	
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