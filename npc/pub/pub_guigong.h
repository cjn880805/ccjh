NPC_BEGIN(CNpub_guigong);

virtual void create()
{
	set_name("龟公","guigong");
	
	set("icon", young_man2);
	set("gender", "男性");
	set("age", 25);
	
	set("long", "一个满脸狠肉的汉子，在丽春院日子久了，养的白白肥肥。");
	set("combat_exp", 30000);
	set("shen_type", 2);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar * me )
{
	switch(random(3))
	{
	case 0:
		return "龟公道：小娘皮，来了这里就乖乖地侍侯大爷们吧。";
	case 1:
		return "龟公道：想跑？跑到天涯海角都给你追回来！";
	case 2:
		return "龟公道：哼！你们这些小贱人，活该！";
	}
	return "";
}

NPC_END;
