//wiz_guard.h
//̩ɽ������
//Lanwood 2001-05-07

NPC_BEGIN(CNwiz_guard);

void create()
{
	set_name("���Է�", "qiao fu");
	set("long", "һ��������ɣ�����ˡ�");
	set("icon", old_man1);
	
	set("gender", "����");
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

	set_inquiry("��ɽ", "�������Ѿ�����ħռ���ˡ���Ȼ������Σ�գ�ȴ�����˱��ء��ȼ�̫����ò�Ҫ��ɽ���װ���������");
	carry_object("changjian")->wield();	
};

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	char msg[255];
	if(strcmp(comm, "go") == 0 && strcmp(arg, "̩ɽ��ڷ�") == 0
		&& me->query("level") < 30)
	{
		say(snprintf(msg, 255, "%s������ס�㣬Ц����ɽ��Σ�գ�%s����Ƶ����С�", name(), query_respect(me)), me);
		SendMenu(me);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg, target);
}

NPC_END;
