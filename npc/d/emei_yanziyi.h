//yanziyi.h
//code by zwb
//12-16

NPC_BEGIN(CNEMei_yanziyi);

virtual void create()
{
		set_name("燕紫衣","yan zi yi");

        set("long","她是峨嵋派一个辈份极高的老尼的关门徒弟。一张脸秀丽绝俗。身着一身淡紫衣裳。这一路上去京师她夺了好几家掌门。");
        set("gender", "女性");
        set("age", 18);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("title", "九家半门派总掌门");
        set("class", "bonze");
        set("chat_chance_combat", 60);

 	set("icon",girl2);
	set("foolid",25);

        set_inquiry("胡飞", "我和胡大哥毕竟没有缘份的。");
		set_inquiry("掌门","我就喜欢抢掌门！");

        set("str", 30);
        set("per", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("hp", 3500);
        set("mp", 3500);
        set("max_mp", 3500);

        set("combat_exp", 1500000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("finger", 150);
        set_skill("parry", 150);
        set_skill("unarmed", 150);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("claw", 150);
        set_skill("literate", 150);
        set_skill("mahayana", 150);
        set_skill("jinding_zhang", 150);
        set_skill("jiuyin_zhua", 150);
        set_skill("tiangang_zhi", 150);
        set_skill("huifeng_jian", 150);
        set_skill("zhutian_bu", 150);
        set_skill("linji_zhuang", 150);
        map_skill("force","linji_zhuang");
        map_skill("claw","jiuyin_zhua");
        map_skill("dodge","zhutian_bu");
        map_skill("strike","jinding_zhang");
        map_skill("sword","huifeng_jian");
        map_skill("parry","huifeng_jian");

        carry_object("changjian")->wield();
        carry_object("ycloth")->wear();
};

virtual char *  greeting(CChar * player)
{
        say ("本姑娘在这里休息，请别来打搅！",player);
        player->move(load_room("hsroad6"));
        return "";
}

virtual char * chat_msg_combat(CChar * player)
{
	char msg[255];
	command(snprintf(msg,255,"cast %ld sword mie",player->object_id()));
	return "";
}
NPC_END;
