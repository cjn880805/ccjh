NPC_BEGIN(CNPub_nongfu);

virtual void create()
{
	set_name("��ũ��","nongfu");
	
	set("icon", banditi);
	set("gender", "����" );
	set("age", 22);
	set("long", "һλ�������ũ�����������Ժ��ò�ɴ���ţ��ϰ�����¶��������Ƥ��");
	set_temp("apply/defense", 15);
	set("combat_exp", 1700);
	set("shen_type", 1);
	set("per", 18);
	set("str", 24);
	set("dex", 25);
	set("con", 36);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("wdahui")->wear();
	carry_object("liandao")->wield();
	
};


NPC_END;
