//wiz_guard.h
//泰山保护神
//Lanwood 2001-05-07

NPC_BEGIN(CNwiz_guard);

void create()
{
	set_name("老樵夫", "qiao fu");
	set("long", "一个饱经沧桑的老人。");
	set("icon", old_man1);
	
	set("gender", "男性");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", 1);
		
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 800000);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 100);
	set_skill("lingxu_bu", 100);
	set_skill("wudu_xinfa", 100);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");

	set_inquiry("上山", "这座上已经被妖魔占领了。虽然充满了危险，却藏满了宝藏。等级太低最好不要上山，白白送死啊。");
	carry_object("changjian")->wield();	
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	char msg[255];
	if(strcmp(comm, "go") == 0 && strcmp(arg, "泰山岱宗坊") == 0
		&& me->query("level") < 30)
	{
		say(snprintf(msg, 255, "%s伸手拦住你，笑道：山上危险，%s最好绕道而行。", name(), query_respect(me)), me);
		SendMenu(me);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg, target);
}

NPC_END;
