//shijiang.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_shijiang);

virtual void create()
{
	set_name("ʯ��","shijiang");
	
	set("icon", triggerman2);
	set("gender", "����" );
	set("age", 52);
	set("long", "����һ����ĥ����ʯ��ʯ��������ֻ����һ�����磬ȫ�����˺�ʵ�ļ��⡣");
	set_temp("apply/defense", 15);
	set("combat_exp", 1700);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 36);
	set("int", 15);
	set("attitude", "friendly");
	set("chat_chance",2);
	
	carry_object("hammer")->wield();
	carry_object("cloth")->wear();
	
};

virtual char * chat_msg(CChar * me)
{
	return "ʯ����һ��ûһ�µ��������е�һ�鱮�ģ���������ţ�����ɽ֮��ʢ����ʯ�����ƴ���ʯ������Ҳ��ʯ���������¡���";
}

NPC_END;
